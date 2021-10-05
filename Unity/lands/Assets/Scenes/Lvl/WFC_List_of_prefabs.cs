using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WFC_List_of_prefabs : MonoBehaviour
{
    
    public static List<GameObject> prefabs; // лист геймобдж

    public List<GameObject> pref;//для проверки листа префабов

    public WFC_MarchingSquares[] ms; //массив WFC_MarchingSquares

    public GameObject[] go;
    
    void Awake()
    {
        //Object[] objects = Resources.LoadAll("Prefab", typeof(GameObject));


        //foreach (GameObject obj in objects)//works
        //{
        //    GameObject lo = (GameObject)obj;
        //    prefabs.Add(lo);
        //}


        //foreach(var pre in prefabs)
        //{
        //    pref.Add(pre);//works
        //}

        prefabs = new List<GameObject>();
        pref = new List<GameObject>();

        ms = GetComponentsInChildren<WFC_MarchingSquares>();//works

        //Debug.Log($"pref count = {pref.Count}");
        //Debug.Log($"ms count = {ms.Length}");
        foreach (var w in ms)//works
        {
            //Debug.Log($"dsa     =   {w}");
            prefabs.Add(w.gameObject);
            //  pref.Add(w.gameObject);
        }
        Start_prefabs();
        Rotate();


        foreach(var tile in prefabs)
        {
            tile.GetComponent<WFC_MarchingSquares>().EdgeToPoints();
        }
        //Test.Display<GameObject>(prefabs);

        



        
    }


    void Start_prefabs()//запускает скрипт на тайлах
    {
        foreach(var tile in prefabs)
        {
            tile.GetComponent<WFC_MarchingSquares>().StartTile();
        }
    }


    void Rotate()
    {


        List<GameObject> gameObjs = new List<GameObject>();
        GameObject go = null;
        foreach (var tile in prefabs)
        {
            Vector3 vec = new Vector3(tile.transform.position.x, tile.transform.position.y, tile.transform.position.z);
            Quaternion quaternion = Quaternion.AngleAxis(0, Vector3.forward);
            //rotation  создание копии тайла и поворот его, соответствующий спину
            switch (tile.GetComponent<WFC_MarchingSquares>().spin)
            {
                case 1:
                    
                    for (int n = 1; n < 4; n++)
                    {
                        vec.Set(vec.x+1, vec.y, 0);
                        quaternion = Quaternion.AngleAxis(90 * n, Vector3.forward);

                        go = Instantiate(tile, vec, quaternion, tile.transform.parent);
                        go.GetComponent<WFC_MarchingSquares>().StartTile();

                        for (int i = 0; i < 4; i++)//выбор грани
                        {
                            // todo
                            int num = i + n;
                            if (num > 3) num -= 4;
                            go.GetComponent<WFC_MarchingSquares>().edge[num].Clear();

                            foreach (var copy in tile.GetComponent<WFC_MarchingSquares>().edge[i])
                            {
                                go.GetComponent<WFC_MarchingSquares>().edge[num].Add(copy);
                            }
                        }
                        go.GetComponent<WFC_MarchingSquares>().rotation_Angle = n;
                        gameObjs.Add(go);
                    }
                    break;


                case 2:
                    vec.Set(vec.x + 1, vec.y, 0);
                    quaternion = Quaternion.AngleAxis(90, Vector3.forward);

                    go = Instantiate(tile, vec, quaternion, tile.transform.parent);
                    go.GetComponent<WFC_MarchingSquares>().StartTile();
                    

                    for (int i = 0; i < 4; i++)//выбор грани
                    {
                        // todo
                        int num = i + 1;
                        if (num > 3) num -= 4;
                        go.GetComponent<WFC_MarchingSquares>().edge[num].Clear();

                        foreach (var copy in tile.GetComponent<WFC_MarchingSquares>().edge[i])
                        {
                            go.GetComponent<WFC_MarchingSquares>().edge[num].Add(copy);
                        }
                    }
                    go.GetComponent<WFC_MarchingSquares>().rotation_Angle = 1;
                    gameObjs.Add(go);
                    break;

            }

        }

        foreach (var obj in gameObjs)
        {
            prefabs.Add(obj);
        }




    }

}
