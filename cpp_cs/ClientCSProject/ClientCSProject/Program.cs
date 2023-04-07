using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace ClientCSProject
{
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct struct_Name_Interop
    {
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 50)]
        public string Name;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 100)]
        public string Address;
        [MarshalAs(UnmanagedType.U8)]
        public ulong Height;
    }

    class Program
    {
        [DllImport("Kernel32.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern bool SetDllDirectory(String lpPathName);

        //[DllImport("C:\\Renjith\\GitHub\\MultiProjectRepo\\Bin\\CppDllProject.dll", EntryPoint = "DisplayHello", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        [DllImport("CppDllProject.dll", CallingConvention = CallingConvention.Cdecl)]
        public static extern void PrintATextFromDll();

        [DllImport("CppDllProject")]
        static extern void FillString(StringBuilder myString, int length);
        
        //[DllImport("CppDllProject.dll", CallingConvention = CallingConvention.Cdecl)]
        [DllImport("CppDllProject.dll")]
        public static extern void UpdateAStruct([MarshalAs(UnmanagedType.Struct)] ref struct_Name_Interop name);

        [DllImport("CppDllProject.dll")]
        public static extern void GetMyString([MarshalAs(UnmanagedType.Struct)] ref struct_Name_Interop name);

        [DllImport("CppDllProject.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        [return: MarshalAs(UnmanagedType.BStr)]
        public static extern string GetMyString();




        static void Main()
        {
            Console.WriteLine("This is from the C# client program");
            
            SetDllDirectory(null); //Restores the default search order
            SetDllDirectory(AppDomain.CurrentDomain.BaseDirectory + "../../Bin/");  //use this  if .exe is in different location
            //SetDllDirectory("../../Bin/");//use this  if this .exe is in different location than the other .dll.                      
            
            PrintATextFromDll();//call a method from native code

            StringBuilder str = new StringBuilder(100);  //reserve storage
            FillString(str, str.Capacity);//call a method from native code
            string myString = str.ToString();
            Console.Out.WriteLine("String received: " + myString);

            var name = new struct_Name_Interop() { Name = "<fill this>", Address = "<fill this too>" };
            UpdateAStruct(ref name); //call a method from native code
            Console.Out.WriteLine("Data structure received from DLL project : " + name.Name + " " + name.Address + " " + name.Height);


            string str2 = GetMyString();
            Console.Out.WriteLine("BSTR received : " + str2);


            Console.In.ReadLine();
        }
    }
}
