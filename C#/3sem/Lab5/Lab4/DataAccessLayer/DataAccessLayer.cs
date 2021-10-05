using System.Transactions;
using System.Data.SqlClient;
using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Logger;

namespace DataAccessLayer
{
    public class DataAccessLayer
    {
        public SqlConnection connection;
        logger log = new logger();


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
                log.AddToLog("SqlConnection: OK\n");
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
                log.AddToLog($"proc_{typeof(T).Name}: OK\n");
            }


            return list;
        }


        public async Task<List<T>> GetAllInstancesAsync<T>() where T : new()
        {
            List<T> list = new List<T>();

            await Task.Run(async () =>
            {
                using (TransactionScope scope = new TransactionScope())
                {
                    SqlCommand sqlCommand = new SqlCommand($"proc_{typeof(T).Name}", connection);
                    sqlCommand.CommandType = System.Data.CommandType.StoredProcedure;


                    SqlDataReader reader = sqlCommand.ExecuteReader();
                    while (reader.Read())
                    {
                        list.Add(await ReadAsync<T>(reader));
                    }


                    reader.Close();
                    scope.Complete();
                    log.AddToLog($"Async proc_{typeof(T).Name}: OK\n");
                }
            });

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

            log.AddToLog("Read<T>: OK\n");

            return obj;
        }


        private async Task<T> ReadAsync<T>(SqlDataReader reader) where T : new()
        {
            T obj = new T();

            await Task.Run(() =>
            {
                for (int i = 0; i < reader.FieldCount; i++)
                {
                    string name = reader.GetName(i);
                    object value = reader.GetValue(i);


                    if (typeof(T).GetProperty(name) != null && value.GetType() != typeof(DBNull))
                    {
                        typeof(T).GetProperty(name).SetValue(obj, value);
                    }
                }
                log.AddToLog("Async Read<T>: OK\n");
            });
            
            return obj;
        }



        /*public List<Models.Person> GetPersonList()
        {
            List<Models.Person> personList = null;
            

            List<Models.BusinessEntity> be = GetAllInstances<Models.BusinessEntity>();
            List<Models.ContactType> ct = GetAllInstances<Models.ContactType>();
            List<Models.CountryRegion> cr = GetAllInstances<Models.CountryRegion>();
            List<Models.EmailAddress> ea = GetAllInstances<Models.EmailAddress>();
            List<Models.PersonPhone> pp = GetAllInstances<Models.PersonPhone>();


            for (int i = 0; i < be.Count; i++)
            {
                personList.Add(new Models.Person(be[i], ct[i], pp[i], cr[i], ea[i]));
            }


            return personList;
        }*/
    }
}
