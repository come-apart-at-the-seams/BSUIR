using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Extract
{
    class ConfigManager//<T> where T : class
    {
        public string ParserPath { get; set; }
        

        

        public ConfigManager(string parserPath)
        {
            Call_Parser(parserPath);
        }


        public static string[] Call_Parser(string parserPath)
        {

            string[] settings;
            var extension = Path.GetExtension(parserPath);
            

            if (extension == ".json")
            {
                IConfigParser<string[]> parser = new JsonParser(parserPath);
                settings = parser.Settings;
                return settings;
            }
            else if (extension == ".xml")
            {
                IConfigParser<string[]> parser = new XmlParser(parserPath);
                settings = parser.Settings;
                return settings;
            }
            return null;
         }
    }
}
