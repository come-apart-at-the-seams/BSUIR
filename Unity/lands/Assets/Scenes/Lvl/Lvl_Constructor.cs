using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Lvl_Constructor : MonoBehaviour
{

    private Transform player_transform;


    private Vector2Int one_gen_size = new Vector2Int(5, 3);
    private GameObject[,] map;
    private WFC_CrLvl wfc_crLvl;
    private int bias = 0;

    private GameObject tmp_swap;

    [Tooltip("Тайл границы")]
    [SerializeField] GameObject _border;
    [SerializeField] GameObject _enemy;


    //private void Update()
    //{
    //    for (int i = 0; i < one_gen_size.x; i++)
    //    {
    //        for (int j = 0; j < one_gen_size.y - 1; j++)
    //        {
    //            map[i, j] = null;
    //        }
    //        tmp_swap = map[i, 0];
    //        map[i, 0] = map[i, one_gen_size.y - 1];
    //        map[i, one_gen_size.y - 1] = tmp_swap;
    //    }


    private void Update()
    {
        if (bias - 2  < player_transform.position.y)
        {
            Add_some_genLines();
            Add_Enemy();
        }
    }


    private void Add_some_genLines()
    {
        //map = wfc_crLvl.CreateLvl(map, one_gen_size);
        //bias += one_gen_size.y - 1;
        //Draw_Map(bias, map);

        for (int i = 0; i < one_gen_size.x; i++)
        {
            for (int j = 0; j < one_gen_size.y - 1; j++)
            {
                map[i, j] = null;
            }
            tmp_swap = map[i, 0];
            map[i, 0] = map[i, one_gen_size.y - 1];
            map[i, one_gen_size.y - 1] = tmp_swap;
        }


        map = wfc_crLvl.CreateLvl(map, one_gen_size);
        bias += one_gen_size.y - 1;
        Draw_Map(bias, map);
    }


    //rename
    void Map_instatoate()
    {
        player_transform = FindObjectOfType<PlayerMove>().transform;
        wfc_crLvl = GameObject.Find("CrLVL").GetComponent<WFC_CrLvl>();
        map = new GameObject[one_gen_size.x, one_gen_size.y];
        tmp_swap = new GameObject();
    }


    public void Get_gen_size(Vector2Int one_gen_size)
    {
        this.one_gen_size = one_gen_size;
    }


    //IEnumerator test_gener()
    //{
    //    yield return new WaitForSeconds(6f);
         
    //    map = wfc_crLvl.CreateLvl(map, one_gen_size);
    //    //todo draw() need to create
    //    //todo add new restart in wfc cr lvl for new generator
    //    //for(int i = 0; i < one_gen_size.x; i++)
    //    //{
    //    //    map2[i, 0] = map[i, one_gen_size.y - 1];
    //    //}
    //}
    //IEnumerator test_gener2()
    //{
    //    map = wfc_crLvl.CreateLvl(map, one_gen_size);
    //    //todo draw() need to create
    //    //todo add new restart in wfc cr lvl for new generator
    //    for (int i = 0; i < one_gen_size.x; i++)
    //    {
    //        map2[i, 0] = map[i, one_gen_size.y - 1];
    //        Debug.Log("Add to map 2");
    //    }

    //    yield return new WaitForSeconds(2f);


    //}


    private void Start()
    {
        Map_instatoate();
        map = wfc_crLvl.CreateLvl(map, one_gen_size);
        bias += one_gen_size.y - 1;
        Draw_Border();
        Draw_Map(bias, map);
    }

    //private void Update()
    //{
    //    for (int i = 0; i < one_gen_size.x; i++)
    //    {
    //        for (int j = 0; j < one_gen_size.y - 1; j++)
    //        {
    //            map[i, j] = null;
    //        }
    //        tmp_swap = map[i, 0];
    //        map[i, 0] = map[i, one_gen_size.y - 1];
    //        map[i, one_gen_size.y - 1] = tmp_swap;
    //    }


    //    map = wfc_crLvl.CreateLvl(map, one_gen_size);
    //    bias += one_gen_size.y - 1;
    //    Draw_Map(bias, map);
    //}


    private void Draw_Map(int bias, GameObject[,] map)
    {
        Vector3Int vec3 = new Vector3Int();
        vec3.z = 0;

        for (int i = 0; i < one_gen_size.x; i++)
        {
            for (int j = 0; j < one_gen_size.y-1; j++)
            {
                vec3.x = i;
                vec3.y = j + bias;
                Quaternion quaternion = map[i, j].transform.rotation;
                Instantiate(map[i, j], vec3, quaternion);
            }
        }

        for (int j = 0; j < one_gen_size.y - 1; j++)
        {
            vec3.x = -1;
            vec3.y = j + bias;
            Quaternion quaternion = _border.transform.rotation;
            Instantiate(_border, vec3, quaternion);

            vec3.x = one_gen_size.x;
            Instantiate(_border, vec3, quaternion);
        }
    }


    private void Draw_Border()
    {
        Vector3Int vec3 = new Vector3Int();
        vec3.z = 0;
        for (int i = -1; i <= one_gen_size.x; i++)
        {
            vec3.x = i;
            vec3.y = 1;

            Quaternion quaternion = _border.transform.rotation;
            Instantiate(_border, vec3, quaternion);
        }
    }

    private void Add_Enemy()
    {
        if( Random.Range(0, 5) == 0)
        {
            Debug.Log("EnemyAttack1");
            Vector3 vector = new Vector3(Random.Range(0, one_gen_size.x), Random.Range(bias, one_gen_size.y + bias), -0.1f);

            Quaternion quaternion = _enemy.transform.rotation;
            Instantiate(_enemy, vector, quaternion);
        }
    }
}
