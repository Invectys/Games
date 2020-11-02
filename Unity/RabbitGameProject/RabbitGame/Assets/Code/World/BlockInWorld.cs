using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlockInWorld : MonoBehaviour
{

    public Block Block { get { return _block; } }
    public EBlocks BlockType;

    private Block _block;

    private void Awake()
    {
        _block = BlockType.CreateObjectByEnum<Block>();
    }

    void Start()
    {
        
    }

    void Update()
    {
        
    }
}

