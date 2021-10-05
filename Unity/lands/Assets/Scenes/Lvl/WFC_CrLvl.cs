
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class WFC_CrLvl : MonoBehaviour
{
    [Tooltip("Обшее кол-во тайлов")]
    public int numb_of_tiles = 8;
    [Tooltip("Размер карты, которую надо сгенерировать")]
    public Vector2Int map_size = new Vector2Int(3, 3);

    [Tooltip("Массив возможных тайлов")]
    private WFC_Tile[,] possible;
    [Tooltip("Координаты тайла с минимальной энтропией")]
    public Vector2Int min_Entropy;

    public GameObject[,] map;

    [Tooltip("Когда карта создана становится истиной и останавливает создание карты")]
    private bool is_created = false;


    public GameObject[,] CreateLvl(GameObject[,] lvl_map, Vector2Int lvl_size) // create lvl from lvl_constructor
    {
        is_created = false;

        map_size = lvl_size;

        possible = new WFC_Tile[map_size.x, map_size.y];

        map = new GameObject[map_size.x, map_size.y];


        for (int i = 0; i < map_size.x; i++)
        {
            for (int j = 0; j < map_size.y; j++)
            {
                if (lvl_map[i, j] != null)
                {
                    possible[i, j] = new WFC_Tile(lvl_map[i, j]);
                }
                else
                {
                    possible[i, j] = new WFC_Tile();
                }  
            }
        }

        Generator();

        return map;
    }


    
    // Start is called before the first frame update
    void Staart()
    {
        possible = new WFC_Tile[map_size.x, map_size.y];

        map = new GameObject[map_size.x, map_size.y];

        
        for (int i = 0; i < map_size.x; i++)
        {
            for(int j = 0; j < map_size.y; j++)
            {
                possible[i, j] = new WFC_Tile();
            }
        }
        //Debug.Log("Start");

        Generator();

    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space))
        {
            Restart();
        }

    }



    void GeneratorRnd()
    {
        Vector3Int pos;
        pos = new Vector3Int(y: Random.Range(0, map_size.y - 1), x: Random.Range(0, map_size.x - 1), z: Random.Range(0, 3)); //add 1st tile

        //CreateTile(pos);

    }




    //IEnumerator Generator()
    //{
    //    while (!is_created)
    //    {
    //        //print("min-entropy");
    //        MinEntropy();
    //        Callapse(min_Entropy);

    //        //
    //        for (int i = 0; i < map_size.x; i++)
    //        {
    //            for (int j = 0; j < map_size.y; j++)
    //            {

    //                if (possible[i, j].possible_tiles.Count == 1)
    //                {
    //                    if (map[i, j] == null)
    //                    {
    //                        PrintTile(i, j);
    //                        yield return new WaitForSeconds(0.2f);
    //                    }

    //                }

    //            }
    //        }
    //        //

    //        if (IsAllCallapsed())
    //        {
    //            CreateTileMap();
    //        }

    //    }
    //}


    void Generator()
    {
        while (!is_created)
        {
            //print("min-entropy");
            MinEntropy();
            Callapse(min_Entropy);

            if (IsAllCallapsed())
            {
                CreateTileMap();
            }

        }
    }



    bool IsAllCallapsed()
    {
        is_created = true;
        foreach(var tile in possible)
        {
            if(tile.possible_tiles.Count != 1)
            {
                is_created = false;
                break;
            }
        }
        return is_created;
    }




    void Callapse(Vector2Int vec)
    {


        possible[vec.x, vec.y].isChecked = true;



        for (int i = -1; i <= 1; i += 2)
        {
            
            if (vec.x + i >= 0 && vec.x + i < map_size.x)
            {
                //print($"vec.x + i= {vec.x} ec.y = {vec.y+1}");
                CallapseNeighbour(vec, vec.x + i, vec.y);
            }
            if (vec.y + i >= 0 && vec.y + i < map_size.y)
            {
                //print($"vec.x= {vec.x + i} ec.y + i = {vec.y}");
                CallapseNeighbour(vec, vec.x, vec.y + i);
            }

        }

    }


    void CallapseNeighbour(Vector2Int vec, int i, int j)
    {

        foreach (var tile in possible[vec.x, vec.y].possible_tiles)
        {
            var comp = tile.GetComponent<WFC_MarchingSquares>();
            int main_derection = 0; //c какой стороны находиться главный таил относительно соседа

            if (vec.x > i) main_derection = 1;
            else if (vec.x < i) main_derection = 3;
            else if (vec.y > j) main_derection = 2;
            else if (vec.y < j) main_derection = 0;

            int neighbour_direcrion = main_derection + 2;// c какой стороны находиться сосед относительно главного таила

            if (neighbour_direcrion > 3) neighbour_direcrion -= 4;

            for (int h = 0; h < possible[i, j].possible_tiles.Count; h++)
            {
                
                var possible_comp = possible[i, j].possible_tiles[h].GetComponent<WFC_MarchingSquares>();
                List<int> list1 = new List<int>(); //нужен для ревёрса листа possible_comp.edge[]


                foreach (var pos in possible_comp.edge[main_derection])
                {
                    list1.Add(pos);
                    //print($"pos= {pos}");
                }
                list1.Reverse();

                
                if (list1.SequenceEqual(comp.edge[neighbour_direcrion]))
                {
                    possible_comp.is_suitable = true;
                }
                
                list1.Clear();

            }



        }

        for (int h = 0; h < possible[i, j].possible_tiles.Count; h++)
        {
            var possible_comp = possible[i, j].possible_tiles[h].GetComponent<WFC_MarchingSquares>();
            if (!possible_comp.is_suitable)//удаление
            {
                possible[i, j].possible_tiles.RemoveAt(h);
                h--;
                //print($"delete neighbour");
            }
            else
            {
                possible_comp.is_suitable = false;
            }
        }
        
    }




    void MinEntropy()
    {
        min_Entropy = new Vector2Int(0, 0);


        for (int i = 0; i < map_size.x; i++)
        {
            for (int j = 0; j < map_size.y; j++)
            {
                int min = possible[min_Entropy.x, min_Entropy.y].possible_tiles.Count;
                int check = possible[i, j].possible_tiles.Count;

                bool isMinCallapsed = possible[min_Entropy.x, min_Entropy.y].isChecked;
                bool isCheckCallapsed = possible[i, j].isChecked;

                if (min == 0)
                {
                    // если есть таил который нельзя заполнить 
                    Restart();
                }
                else if (isMinCallapsed && !possible[i, j].isCallapsed)
                {
                    //если уже скалапсирован
                    min_Entropy.x = i;
                    min_Entropy.y = j;
                }
                else if (min > check /*&& check - 1 > 0*/ && !isCheckCallapsed && possible[i, j].isCallapsed)
                {
                    min_Entropy.x = i;
                    min_Entropy.y = j;
                }
            }
        }

        if (possible[min_Entropy.x, min_Entropy.y].possible_tiles.Count == 0)
        {

            Restart();
        }


        //если все скалапсированы
        //проверяем есть ли максимальная энтропия большая единицы
        // todo check this - all is ok
        if (possible[min_Entropy.x, min_Entropy.y].isChecked)
        {
            // если кол-во тфйлов у мин энтропиией больше 1 то выбираем рандомный таил
            while(possible[min_Entropy.x, min_Entropy.y].possible_tiles.Count > 1) 
            {
                //todo когда добавят веса здеcь необходимо изменить генерацию
                int f = Random.Range(0, possible[min_Entropy.x, min_Entropy.y].possible_tiles.Count);
                possible[min_Entropy.x, min_Entropy.y].possible_tiles.RemoveAt(f);
                //possible[min_Entropy.x, min_Entropy.y].possible_tiles.RemoveAt
                //    (Random.Range(0, possible[min_Entropy.x, min_Entropy.y].possible_tiles.Count));
            }
            possible[min_Entropy.x, min_Entropy.y].isCallapsed = true;
            Make_isChecked_false();
            //for (int i = 0; i < map_size.x; i++)
            //{
            //    for (int j = 0; j < map_size.y; j++)
            //    {
            //        if(possible[i, j].possible_tiles.Count > 1)
            //        {
            //            Make_isChecked_false();
            //            return;
            //        }
            //    }
            //}
        }
    }




    void CreateTileMap()
    {
        //is_created = true;
        Vector3Int vec3 = new Vector3Int();
        vec3.z = 0;
        for (int i = 0; i < map_size.x; i++)
        {
            for (int j = 0; j < map_size.y; j++)
            {
                vec3.x = i;
                vec3.y = j;
                Quaternion quaternion = possible[i, j].possible_tiles[0].transform.rotation;
                //map[i, j] = Instantiate(possible[i, j].possible_tiles[0], vec3, quaternion);
                map[i, j] = possible[i, j].possible_tiles[0];

               //print("ADD TO MAP");
            }
        }
    }


    void Make_isChecked_false()
    {
        for (int i = 0; i < map_size.x; i++)
        {
            for (int j = 0; j < map_size.y; j++)
            {
                possible[i, j].isChecked = false;
            }
        }
    }


    void Restart()
    {
        print("RESTART");
        Staart();
    }


    void PrintTile(int i, int j)
    {
        

        Vector3Int vec3 = new Vector3Int();
        vec3.z = 0;

        vec3.x = i + 10;
        vec3.y = j + 10;
        //var possible_comp = possible[i, j].possible_tiles[0].GetComponent<WFC_MarchingSquares>();
        Quaternion quaternion = possible[i, j].possible_tiles[0].transform.rotation;
        map[i, j] = Instantiate(possible[i, j].possible_tiles[0], vec3, quaternion);   
    }

}




//  в  map  хранятся уже готовые тайлы

//  ____________TODO
// надо создать новый класс который описывает таилмэп. В себя включает:
// карту возможных тайлов
// карту тайлов с буллевфми значеними которые показывают каллапсирывали ли мы соседей
