using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Test : MonoBehaviour
{
    public static void Display<T>(List<T> list) // for  print list<T>
    {
        foreach(var tmp in list)
        {
            Debug.Log("Display<T> \t" + tmp);
        }
    }

    public static void Display<T>(List<T> list, string str) // for  print list<T>
    {
        foreach (var tmp in list)
        {
            Debug.Log($"{str} =\t{tmp}");
        }
    }

    
}
