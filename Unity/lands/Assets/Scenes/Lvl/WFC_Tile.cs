using System.Collections.Generic;
using UnityEngine;

public class WFC_Tile
{
    [Tooltip("Лист возможных тайлов")]
    public List<GameObject> possible_tiles = new List<GameObject>();
    //public List<WFC_MarchingSquares> tiles_Settings = new List<WFC_MarchingSquares>();
    [Tooltip("Использовался ли тайл для коллапса соседей")]
    public bool isChecked = false;

    [Tooltip("Был ли тайл сколаписовован")]
    public bool isCallapsed = false;
    //[Tooltip("Угл поворота")]
    //public int Rotation_Angle = 0;

    public WFC_Tile()
    {
        
        foreach (GameObject prefab in WFC_List_of_prefabs.prefabs)
        {
            possible_tiles.Add(prefab);
        }

        
        
    }

    public WFC_Tile(List<GameObject> tiles)
    {
        if (tiles.Count < 1)
        {
            Debug.Log("input error. List ids empty or -size");
        }

        // need to check
        if (tiles.Count == 1)
        {
            isCallapsed = true;
        }


        foreach (var tile in tiles)
        {
            tile.GetComponent<WFC_MarchingSquares>().StartTile();
            possible_tiles.Add(tile);
        }
        
    }
    public WFC_Tile(GameObject tile)
    {
        if (tile == null)
        {
            Debug.Log("input error. gameobj is empty or null");
        }

        // need to check
        
        isCallapsed = true;
        tile.GetComponent<WFC_MarchingSquares>().StartTile();
        possible_tiles.Add(tile);
        

    }

}


    




