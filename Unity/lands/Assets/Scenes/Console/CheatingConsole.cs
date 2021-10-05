using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class CheatingConsole : MonoBehaviour
{
    private bool isConsoleVisible = false;
    private string input;

    public static CheatCommand ADD_SPEED;
    public static CheatCommand NORM_SPEED;
    public List<object> commandList;


    private void Awake()
    {
        ADD_SPEED = new CheatCommand("add_speed", "ADD 10f m/s", "add_speed", () =>
        {
            Debug.Log("CHeating");
            
            GameObject.Find("Player").GetComponent<PlayerMove>().Get_speed_normal(10f);
        });

        NORM_SPEED = new CheatCommand("norm_speed", "ADD 3f m/s", "norm_speed", () =>
        {
            Debug.Log("CHeating");

            GameObject.Find("Player").GetComponent<PlayerMove>().Get_speed_normal(4f);
        });

        commandList = new List<object>
        {
            ADD_SPEED,
            NORM_SPEED,
        };
    }

    public void OnReturn()
    {
        if (isConsoleVisible)
        {
            HendleInput();
            input = "";
        }
    }

    private void HendleInput()
    {
        for (int i = 0; i < commandList.Count; i++)
        {
            CheatCommandsBase commandsBase = commandList[i] as CheatCommandsBase;
            if (input.Contains(commandsBase.commandID))
            {
                if (commandList[i] as CheatCommand != null)
                {
                    (commandList[i] as CheatCommand).Invoke();

                }
            }
           
        }
    }

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.Tab))
        {
            OnReturn();
            isConsoleVisible = !isConsoleVisible;
            
        }
    }

    private void OnGUI()
    {
        if (isConsoleVisible)
        {
            float y = 0f;
            GUI.Box(new Rect(0, y, Screen.width, 30), "");
            GUI.backgroundColor = new Color(0, 0, 0, 0);
            input = GUI.TextField(new Rect(10f, y + 5f, Screen.width - 20f, 20f), input);
        }
        else
        {
            return;
        }
    }
}
