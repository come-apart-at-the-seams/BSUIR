using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;

namespace Lab2_Extract
{
    class JsonParser : IConfigParser<string[]>
    {
        public string[] Settings { get; set; }

        public JsonParser(string parserPath)
        {
            Settings = Parse(parserPath);
        }

        

        public string[] Parse(string parsePath)
        {
            string json;
            List<string> list = new List<string>();
            //List<T> l = new List<T>();


            using (FileStream file = new FileStream(parsePath,
                                        FileMode.Open))
            {
                using (StreamReader reader = new StreamReader(file))
                {
                    json = reader.ReadToEnd();
                }
            }
            Console.WriteLine(json);

            var deserialed = JsonConvert.DeserializeObject<EtlJsonOptions>(json);


            list.Add(deserialed.TargetDirectory.ToString());
            foreach (byte k in deserialed.Key)
            {
                list.Add(k.ToString());
            }
            foreach (byte k in deserialed.Iv)
            {
                list.Add(k.ToString());
            }
            
            string[] settings = list.ToArray();
            foreach (string l in settings)
            {
                Console.WriteLine(l);
            }

            
            return settings;
        }

        


    }
}
