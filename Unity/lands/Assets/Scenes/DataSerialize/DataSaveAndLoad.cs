using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;

public class DataSaveAndLoad
{
    public static void SaveToFile(DataSerializer data)
    {
        BinaryFormatter binaryFormatter = new BinaryFormatter();
        string path = Application.persistentDataPath + "/save.fgi";


        using(FileStream fileStream = new FileStream(path, FileMode.Create))
        {
            binaryFormatter.Serialize(fileStream, data);
        }
    }



    public static DataSerializer LoadFromFile()
    {
        BinaryFormatter binaryFormatter = new BinaryFormatter();
        DataSerializer data = new DataSerializer();
        string path = Application.persistentDataPath + "/save.fgi";


        if (File.Exists(path))
        {
            using (FileStream fileStream = new FileStream(path, FileMode.Open))
            {
                data = binaryFormatter.Deserialize(fileStream) as DataSerializer;
            }
        }

        return data;
    }
}
