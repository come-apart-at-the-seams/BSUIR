using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    [SerializeField] private bool _gameHasEnded = false;

    [SerializeField] private GameObject _endGameUI;

    [SerializeField] private GameObject _text;

    [SerializeField] private GameObject _player;

    public static GameManager isntance { get; private set; }



    private void Awake()
    {
        if (isntance == null)
        {
            isntance = this;
            //DontDestroyOnLoad(isntance.gameObject);
            return;
        }
        
        Destroy(this.gameObject);
        



    }


    public void EndGame()
    {
        
        if (_gameHasEnded == false)
        {
            
      
            _gameHasEnded = true;
            //Debug.Log("GameEnd");
            SetActiveEndUI();
            _player.GetComponent<PlayerMove>().enabled = false;
            DataSaveAndLoad.SaveToFile(new DataSerializer(_player.transform.position.y));
            Invoke("Restart", 4f);
        }   
    }

    private void Restart()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
        
    }

    private void SetActiveEndUI()
    {
        _text.SetActive(false);
        _endGameUI.SetActive(true);
        _player.GetComponent<Score>().endGameUI();
        

    }
}
