// JsonParser.cpp
//Parse Json string that is in C++ format and retreive its Key/Values

#include <map>
#include <string>
#include <iostream>

using namespace std;


std::map<std::string, std::string> StringToMap(std::string const& jsonStringToMap){
    std::map<std::string, std::string> mapResult;

    std::string::size_type key_StartPos = 0;
    std::string::size_type key_EndPos;
    std::string::size_type val_Startpos;
    std::string::size_type val_EndPos;

    //find the next :
    while ((key_EndPos = jsonStringToMap.find(':', key_StartPos)) != std::string::npos){
        //find the character that does not match any of the characters specified.  Ensuring no more to parse.
        if ((val_Startpos = jsonStringToMap.find_first_not_of(":", key_EndPos)) == std::string::npos)
            break;

        val_EndPos = jsonStringToMap.find(',', val_Startpos);
        if (jsonStringToMap[val_Startpos] == '['){//Note: if multiple values are in for a key: ex: { USZones : [HST, AKDT, PST, MST, CST, EST] }
            val_EndPos = jsonStringToMap.find(']', val_Startpos) + 1;
        }
        mapResult.emplace(jsonStringToMap.substr(key_StartPos, key_EndPos - key_StartPos), jsonStringToMap.substr(val_Startpos, val_EndPos - val_Startpos));

        key_StartPos = val_EndPos;
        if (key_StartPos != std::string::npos)
            key_StartPos ++;
    }
    return mapResult;
}

std::map<std::string, std::string> PackJsonIntoKVmap(std::string jsonString){
    jsonString.erase(std::remove(jsonString.begin(), jsonString.end(), '{'), jsonString.end());
    jsonString.erase(std::remove(jsonString.begin(), jsonString.end(), '}'), jsonString.end());
    jsonString.erase(std::remove(jsonString.begin(), jsonString.end(), '\"'), jsonString.end());
    jsonString.erase(std::remove(jsonString.begin(), jsonString.end(), ' '), jsonString.end());

    //now we got a string.  Split it and push to a map
    auto kvMap = StringToMap(jsonString);
    return kvMap;
}

int main(){
    std::string receievedJsonString = "{\"access_token\":\"N0IjpbIkVs0Vd9CMtmIs64gFbc-NRLKNAHUm846qVeUMu3T-SnFTAut-rdMussc-k9pPUVp1xthHhDL7Q\", \"USZones\" : \"[HST, AKDT, PST, MST, CST, EST]\", \"token_type\" : \"bearer\", \"expires_in\" : 3600}";
    
    auto jsonMap = PackJsonIntoKVmap(receievedJsonString);

    string strSearchKey = "expires_in";
    auto item = jsonMap.find(strSearchKey);
    if (item != jsonMap.end()) {
        cout << item->first  << " : "<< item->second <<endl;
    }
    else {
        cout << "Key does not exist!" << endl;
    }
    
    return 0;
}
