using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(fileName = "Data", menuName = "ScriptableObjects/TerrainSettings", order = 1)]
public class SOTerrain : ScriptableObject
{
    public PerlinBlock[] PerliBlocksRow; 
}

[Serializable]
public class PerlinBlock
{
    public BlockInWorld block;
    public float perlinPointValue;
}

