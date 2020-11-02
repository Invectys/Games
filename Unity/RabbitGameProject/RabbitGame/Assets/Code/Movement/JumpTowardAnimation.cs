using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class JumpTowardAnimation : MovementAnimation
{

    public float Heigth = 2f;

    public override void ApplyParameters(Parameters parameters)
    {
        Heigth = parameters.GetFloat("Heigth");
    }

    public override Vector3 MovementFunction()
    {
        return MathParabola.Parabola(StartPos, TargetPos, Heigth, AnimationTime);
    }
}
