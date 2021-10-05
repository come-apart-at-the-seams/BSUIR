using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Extract
{
    public class EtlXmlOptions
    {
        public string TargetDirectory { get; set; }
        public string Key { get; set; }
        public string Iv { get; set; }

        public EtlXmlOptions() { }
    }
}
