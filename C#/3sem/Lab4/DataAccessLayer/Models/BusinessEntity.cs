using System;
using System.Collections.Generic;
using System.Text;

namespace DataAccessLayer.Models
{
    public class BusinessEntity
    {
        public int BusinessEntityID { get; set; }
        public Guid Rowguid { get; set; }
        public DateTime ModifiedDate { get; set; }
    }
}
