using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EGG : MonoBehaviour
{
    [SerializeField] private GameObject _go;
    // Update is called once per frame
    void Update()
    {
        if (Input.GetKey(KeyCode.Escape) && Input.GetKey(KeyCode.F))
        {
            _go.SetActive(true);
        }
        
    }

    public void buttom()
    {
        _go.SetActive(false);
    }
}
