using System;
using System.Collections.Generic;
using System.Text;

namespace Data_Access_Layer.Options
{
    class ConnectionOptions
    {
        public string DataSource { get; set; } = "LAPTOP-UMSHNN8K";
        public string DataBase { get; set; } = "AdventureWorks2019";
        public string IntegratedSecurity { get; set; } = "SSPI";
        public string Pooling { get; set; } = "False";
    }
}
