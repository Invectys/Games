using System;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices.WindowsRuntime;
using UnityEngine;

public static class Extension 
{

    public static Type GetTypeByEnum(this object enumAnim)
    {
        Type type = Type.GetType(enumAnim.ToString());
        return type;
    }

    public static T CreateObjectByEnum<T>(this object enumAnim)
    {
        Type type = GetTypeByEnum(enumAnim);
        T obj = (T)Activator.CreateInstance(type);
        return obj;
    }

  

    public static int X(this Vector3 loc) => (int)loc.x;
    public static int Z(this Vector3 loc) => (int)loc.z;
}
