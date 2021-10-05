using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpeedTrigger : MonoBehaviour
{
    [SerializeField]
    [Tooltip("Скорость при выходе")]
    private float exit_speed = 0f;

    [SerializeField]
    [Tooltip("Скорость  при входе")]
    private float enter_speed = 3f;

    [SerializeField]
    [Tooltip("Скорость в течении движения")]
    private float stay_speed = 0f;


    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.gameObject.GetComponent<PlayerMove>() != null)
        {
           
            collision.gameObject.GetComponent<PlayerMove>().Get_speed_trigger(enter_speed);
            
        }
    }


    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.gameObject.GetComponent<PlayerMove>() != null)
        {
            collision.gameObject.GetComponent<PlayerMove>().Get_speed_trigger(exit_speed);
            //collision.gameObject.GetComponent<Rigidbody2D>().AddForce
            //    (new Vector2(10000f, 10000f), ForceMode2D.Impulse);
        }
    }


    private void OnTriggerStay2D(Collider2D collision)
    {
        if (collision.gameObject.GetComponent<PlayerMove>() != null)
        {
            collision.gameObject.GetComponent<PlayerMove>().Get_speed_trigger(stay_speed);
        }
    }

}
