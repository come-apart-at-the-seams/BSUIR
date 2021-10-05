using System;
using System.Collections.Generic;
using System.Text;

namespace Data_Access_Layer.Options
{
    class Data_Access_LayerOptions
    {
        public ConnectionOptions ConnectionOptions { get; set; } = new ConnectionOptions();
        public DirectoryOptions DirectoryOptions { get; set; } = new DirectoryOptions();
    }
}
