using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class Parameters
{

    List<Parameter> _paramsList;

    public Parameters(List<Parameter> parameters)
    {
        _paramsList = parameters;
    }

    public float GetFloat(string key)
    {
        return float.Parse(_paramsList.First(n => n.key == key).value);
    }

    public Parameters Set(string key,string obj)
    {
        var note = _paramsList.FirstOrDefault(n => n.key == key);
        if (_paramsList.FirstOrDefault(n => n.key == key) != null)
        {
            note.value = obj;
        }
        else
        {
            _paramsList.Add(new Parameter() { key = key, value = obj});  
        }
        return this;
    }

}

[Serializable]
public class Parameter
{
    public string key;
    public string value;
}
