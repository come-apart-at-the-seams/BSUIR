using System;
using System.Collections.Generic;
using System.Text;

namespace Data_Access_Layer.Models
{
    class ContactType
    {
        public int ContactTypeID { get; set; }
        public string Name { get; set; }
        public DateTime ModifiedDate { get; set; }
    }
}
