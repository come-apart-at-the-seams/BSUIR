using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CheatCommandsBase
{
    private string _commandId;
    private string _commandDescripton;
    private string _commandFormat;

    public string commandID { get { return _commandId; } }
    public string commandDescripton { get { return _commandDescripton; } }
    public string commandFormat { get { return _commandFormat; } }

    public CheatCommandsBase(string id, string descripton, string format)
    {
        _commandId = id;
        _commandDescripton = descripton;
        _commandFormat = format;
    }

}


public class CheatCommand : CheatCommandsBase
{
    private Action command;

    public CheatCommand(string id, string descripton, string format, Action command)
        : base(id, descripton, format)
    {
        this.command = command;
    }

    public void Invoke()
    {
        command.Invoke();
    }
}