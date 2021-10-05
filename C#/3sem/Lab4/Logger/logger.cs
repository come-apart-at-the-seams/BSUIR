using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Threading.Tasks;

namespace Logger
{
    public class logger
    {
        const string SpecialDirectory = @"D:\work\documents\Study\3sem\ИСП"
                                        + @"\SpecialDirectory";

        public  void AddToLog(string log)
        {
             
                    using StreamWriter writer = new StreamWriter(SpecialDirectory + @"\log.txt", true);
                    writer.WriteLine(log);
            
        }
    }
}
