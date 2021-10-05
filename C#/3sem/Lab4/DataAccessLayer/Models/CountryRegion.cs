using System;
using System.Collections.Generic;
using System.Text;

namespace DataAccessLayer.Models
{
    public class CountryRegion
    {
        public string CountryRegionCode { get; set; }
        public string Name { get; set; }
        public DateTime ModifiedDate { get; set; }
    }
}
