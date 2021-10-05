using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Linq;

public class WFC_MarchingSquares : MonoBehaviour
{
    //public byte points;
    //public int tile_index;

    //public string tile_name = GameObject.

    
    public int[] points = new int[8];       // значения 0 1 8
    [Tooltip("есть ли смысл отражать тайл")]
    public bool is_reflected;               //есть ли смысл отражать тайл
    [Tooltip("спин тайла. 4 - все 4 стороны равны между собой, 2 - две, 1 - 0")]
    public int spin;

    //[SerializeField]
    [Tooltip("массив р>бер нужен для выбора какой тайл подходит")]
    public List<int>[] edge= new List<int>[4];         //массив р>бер нужен для выбора какой тайл подходит 

    [SerializeField]
    private int amount_of_points = 3;       //количество точек на одном ребре

    [Tooltip("Угл повората тайла. from 0 to 3")]
    public int rotation_Angle = 0;
    //public List<int> rotation_Angles = new List<int>();
    [Tooltip("Подходящий ли этот таил-сосед для главного тайла. Если неподходит для всех то ложь. Начальное значение ложь")]
    public bool is_suitable = false;

    // Start is called before the first frame update
    public void StartTile()
    {
        //tile_index = points[0] + points[1] * 2 + points[2] * 4 + points[3] * 8 + points[4] * 16 + points[5] * 32 + points[6] * 64 + points[7] * 128;
        //Debug.Log("Start MS!!!!!");
        
            // получаю массив р>бер
        for (int i=0; i< edge.Length; i++)
        {
            edge[i] = new List<int>();

            for (int j = 0; j < amount_of_points; j++)
            {
                if ((i * 2) + j < points.Length)
                {
                    edge[i].Add(points[(i * 2) + j]);
                }
                else
                {
                    edge[i].Add(points[0]);
                }
            }
            
            //if (i==2 || i==3)
            //{
            //    edge[i].Reverse();
            //}
        }

        //for (int i = 0; i < edge.Length; i++)
        //{
        //    print(GetComponent<WFC_MarchingSquares>().name);
        //}

        Spin();

        
        
    }



    //определяем "поворотность" объекта, spin
    void Spin()
    {
        if (edge[0].SequenceEqual(edge[1]) &&
            edge[0].SequenceEqual(edge[2]) &&
            edge[0].SequenceEqual(edge[3]))
        {
            //1
            spin = 4;

        }
        else if(edge[0].SequenceEqual(edge[2]) &&
                edge[3].SequenceEqual(edge[1]))
        {
            //2
            spin = 2;

        }
        else
        {
            //4
            spin = 1;

        }
    }


    public void EdgeToPoints()
    {
        for (int i = 0; i < edge.Length; i++)
        {
            for (int j = 0; j < edge[0].Count; j++)
            {
                int num = (i * 2) + j;
                
                if(num == 8)
                {
                    break;
                }
                points[num] = edge[i][j];
            }
            
        }

    }


  


    



    void massSochetaniy()
    {

    }
}
