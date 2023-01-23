/*
Many automated trading systmes continiously consume market data, tehn react when certain
specific conditions are met.  One such condition occurs when the prices of two highly correlated 
stocks diverge.  
PriveDivergenceMonitory class:
    1. The constructor takes in a threashold.
    2. The RegisterPair() will be called each time it wants your calss to start monitoring new pair or correlated stocks.
      2.a.Mulitple pairs can/will be registered and you need to monitor all registered pairs.
    3. The UpdatePrice() will be called whenever the price of stock changes.
      3.a When the price change you should chekc whther that new price differs from the price of the other stock in the pair by more than the threashold.
            if it doesn, call ReportDivergence().
      3.b. If the differnce is exactly the threashold, do nothing.
      3.c. if you have not received the price for a product, do nothing.
      3.d. ignore registering pairs if they are already registered.
*/


#include <string>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

int timeStamp = 0;
vector<string> eventOutput;


//using a datastructure to store the pairs (name and price).
typedef struct {
    string stockOne; //name of first stock
    string stockTwo; //name of second stock 
    int priceOne; //price of first stock
    int priceTwo; //price of second stock
}stockPair_t;

class PriceDivergenceMonitor
{
  public:
    PriceDivergenceMonitor(int threshold);
    void RegisterPair(const string& stockOne, const string& stockTwo);
    void UpdatePrice(const string& stockName, int newPrice);
  private:
    void ReportDivergence(const string& updatedStockName, int updatedStockPrice, const string& otherStockName, int otherStockPrice);
    // todo: add member variables, if needed
    
    int m_threashold;
    vector<stockPair_t> StockPair; //capture all pairs here.
    bool CanAlert(int index); //an utility method to avoid redudant code.
};


PriceDivergenceMonitor::PriceDivergenceMonitor(int threshold)
{
    m_threashold = threshold; //initializing threashold.
}

/*
The method RegisterPair will be called by the owner of this class each time it wants your class to start monitoring a new pair of correlated stocks.
*/
void PriceDivergenceMonitor::RegisterPair(const string& stockOne, const string& stockTwo)
{
    // todo: complete this method
    int vecSize = StockPair.size();
    for (int index = 0; index < vecSize; index++){ //not the best way to do.
        if (StockPair[index].stockOne == stockOne && StockPair[index].stockTwo == stockTwo){
            //cout<<"already registered.";
            return;
        }
        if (StockPair[index].stockOne == stockTwo && StockPair[index].stockTwo == stockOne){
            //cout<<"already registered.";
            return;
        }
    }
            
        
    stockPair_t tmpObj;
    tmpObj.stockOne = stockOne;
    tmpObj.stockTwo = stockTwo;
    tmpObj.priceOne = 0;
    tmpObj.priceTwo = 0;
    
    StockPair.push_back(tmpObj);
}

//CanAlert will return true if the -
//a. stockprice is initialized (not equal to 0)
//b. one stockprice is different than the threashold of second stock price
bool PriceDivergenceMonitor::CanAlert(int index){
    if (StockPair[index].priceOne == 0 || StockPair[index].priceTwo == 0){
        return false;
    }
    int priceOne = StockPair[index].priceOne ;
    int priceTwo = StockPair[index].priceTwo;
    
    int Diff = abs(StockPair[index].priceOne - StockPair[index].priceTwo);
    if ( Diff > m_threashold)
    {
        //cout<<"returning true: "<<StockPair[index].priceOne << StockPair[index].priceTwo<<endl;
        return true;
    }
    return false;
}

/*
The method UpdatePrice will be called by the owner of this class whenever the price of a stock changes. When the price of a stock that is part of a registered pair changes, you should check whether that new price differs from the price of the other stock in the pair by more than the threshold. If it does, call the ReportDivergence method with the appropriate parameters.
*/
void PriceDivergenceMonitor::UpdatePrice(const string& stockName, int newPrice)
{
    // todo: complete this method
    int vecSize = StockPair.size();
    for (int index = 0; index < vecSize; index++){ //not the best way to do.
        if (StockPair[index].stockOne == stockName){ //matching name found.
            StockPair[index].priceOne = newPrice;
            //cout<<"match found #1\n";
            
            if (CanAlert(index)) //difference in threashold, alert.
            {
                ReportDivergence(StockPair[index].stockOne, StockPair[index].priceOne, StockPair[index].stockTwo, StockPair[index].priceTwo);
            }
            else {
                //cout<<"can't alert #1\n";
            }
        }
        else if (StockPair[index].stockTwo == stockName){
            StockPair[index].priceTwo = newPrice;
            //cout<<"match found #2\n";
            if (CanAlert(index)){
                ReportDivergence(StockPair[index].stockTwo, StockPair[index].priceTwo, StockPair[index].stockOne, StockPair[index].priceOne);
            }
            else {
                //cout<<"cant' alert #2\n";
            }
        }     
    }
}


void PriceDivergenceMonitor::ReportDivergence(const string& updatedStockName, int updatedStockPrice, const string& otherStockName, int otherStockPrice)
{
    ostringstream os;
    os << timeStamp << " " << updatedStockName << " " << updatedStockPrice << " " << otherStockName << " " << otherStockPrice;
    eventOutput.push_back(os.str());
}

int main()
{
    int tolerance; 
    cout<<"Enter price tolerance : ";
    cin >> tolerance;
    
    PriceDivergenceMonitor pdm(tolerance);
    
    int numLines;
    cout<<"Enter number of lines: ";
    cin >> numLines;

    string lineType;
    for (int i = 0; i < numLines; i++)
    {
        cout<<"Enter choice (A (add pair), P (update price) : ";
        cin >> lineType;
        
        if (lineType.compare("A") == 0) {
            string productOne, productTwo;
            cout<<"Enter two product names : ";
            cin >> productOne >> productTwo;
            pdm.RegisterPair(productOne, productTwo);
        } else if (lineType.compare("P") == 0) {
            string product;
            int price;
            cout<<"Enter product name and new price: ";
            cin >> product >> price;
            pdm.UpdatePrice(product, price);
            timeStamp += 1;
        } else {
            cout << "DEBUG: unknown input type" << endl;
            return -1;
        }
    }
    
    // write out output
    sort(eventOutput.begin(), eventOutput.end());
    for (auto it = eventOutput.begin(); it != eventOutput.end(); ++it)
    {
        cout << *it << endl;
    }
    return 0;
}
