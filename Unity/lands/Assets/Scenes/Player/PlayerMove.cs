using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMove : MonoBehaviour
{
    public Rigidbody2D rb;
    [Tooltip("Вектор направления движения")]
    public Vector2 moveVec;

    [SerializeField]
    [Tooltip("Скорость игрока")]
    private float speed_normal = 3f;

    [Tooltip("скорость")] private float speed;

    [SerializeField]
    [Tooltip("Добавочная скорость игрока под шифтом")]
    private float speed_boost = 10f;

    private float speed_trigger = 0f;


    public void Get_speed_trigger(float fspeed)
    {
        if (speed < 100)
        {
            speed_trigger = fspeed;
        } 
    }

    public void Get_speed_normal(float fspeed)
    {
        if (speed < 100)
        {
            speed_normal = fspeed;
        }
    }

    // Update is called once per frame
    void Update()
    {
        //todo переделатиь под состояние мув для того чтобы двежение переопределять в н>м
        if (Input.GetKey(KeyCode.LeftShift))
        {
       
                speed = speed_boost + speed_trigger;
            
            
        }
        else
        {
            speed = speed_normal + speed_trigger;
        }
        moveVec.x = Input.GetAxis("Horizontal");
        moveVec.y = Input.GetAxis("Vertical");
        rb.velocity = new Vector2(moveVec.x * speed, moveVec.y * speed);
    }
}
