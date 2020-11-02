using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CanStayOn : MonoBehaviour
{

    public List<EBlocks> CanStayOnBlocks = new List<EBlocks>();

    public bool isPossibleStayOn(int x,int z)
    {
        World world = Game.GetInstance().GetWorld();
        if (world == null) return true;
        BlockInWorld block = world.GetBlock(x, z);
        return CanStayOnBlocks.Contains(block.BlockType);
    }

    
}
