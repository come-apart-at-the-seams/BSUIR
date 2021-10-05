using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab2_Extract
{
    class EtlJsonOptions
    {
        public string TargetDirectory { get; set; }
        public byte[] Key { get; set; }
        public byte[] Iv { get; set; }

    }
}
