using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class DataSerializer
{
    public float maxScore;
    public float lastScore;


    public DataSerializer(float score)
    { 
        maxScore = getMaxScore(score);
        lastScore = score;
    }

    public DataSerializer()
    {
        maxScore = 0;
        lastScore = 0;
    }


    private float getMaxScore(float score)
    {
        maxScore = DataSaveAndLoad.LoadFromFile().maxScore;
        if(score > maxScore)
        {
            return score;
        }
        return maxScore;
    }

}
