using System.Transactions;
using System.Data.SqlClient;
using System;
using System.Collections.Generic;

namespace Data_Access_Layer
{
    class DataAccessLayer
    {
        public SqlConnection connection;

        public DataAccessLayer(Options.ConnectionOptions options)
        {
            string connectionStr = $"Data Source={options.DataSource};"
                                    + $" Database={options.DataBase}; "
                                    + $"Integrated Security={options.IntegratedSecurity};"
                                    + $"Pooling={options.Pooling}";
            
            
            using (TransactionScope scope = new TransactionScope())
            {
                connection = new SqlConnection(connectionStr);
                
                connection.Open();

                
                scope.Complete();
            }
        }

        public List<T> GetAllInstances<T>() where T : new()
        {
            List<T> list = new List<T>();


            using (TransactionScope scope = new TransactionScope())
            {
                SqlCommand sqlCommand = new SqlCommand($"proc_{typeof(T).Name}", connection);
                sqlCommand.CommandType = System.Data.CommandType.StoredProcedure;


                SqlDataReader reader = sqlCommand.ExecuteReader();
                while (reader.Read())
                {
                    list.Add(Read<T>(reader));
                }


                reader.Close();
                scope.Complete();

            }


            return list;
        }

        private T Read<T>(SqlDataReader reader) where T : new()
        {
            T obj = new T();


            for (int i = 0; i < reader.FieldCount; i++)
            {
                string name = reader.GetName(i);
                object value = reader.GetValue(i); 


                if (typeof(T).GetProperty(name) != null && value.GetType() != typeof(DBNull))
                {
                    typeof(T).GetProperty(name).SetValue(obj, value);
                }
            }


            return obj;
        }
    }
}
