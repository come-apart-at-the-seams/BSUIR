using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class Score : MonoBehaviour
{
    [SerializeField] private Transform _transform;
    [SerializeField] public Text _scoreText;
    [SerializeField] public Text _scoreText1;
    [SerializeField] public Text recordScore;
    [SerializeField] public Text lastScore;
    [SerializeField] private float _score;
    //[SerializeField] private float _lastScore;
    [SerializeField] private float _saveScore;

    // Update is called once per frame
    private void Update()
    {
        _score = _transform.position.y;
        _scoreText.text = _score.ToString("0");
        
    }

    public void endGameUI()
    {
        _saveScore = _score;
        _scoreText1.text = _saveScore.ToString("0");


        DataSerializer data = DataSaveAndLoad.LoadFromFile();
        recordScore.text = data.maxScore.ToString("0");

        lastScore.text = data.lastScore.ToString("0");

    }
}
