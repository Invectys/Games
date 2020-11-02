using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    public delegate void Action();
    public event Action StepEndEvent;

    public CanStayOn CanStayOn;
    public EAnimationTypes MoveAnimation;
    public List<Parameter> Parameters = new List<Parameter>();

    Transform _transform;
    Type _animation;
    bool _stepStarted = false;

    

    public void Step(Vector3 dir)
    {
        Vector3 targetPosition = _transform.position + dir;
        if (!_stepStarted)
        {
            if (CanStayOn.isPossibleStayOn(targetPosition.X(),targetPosition.Z()))
            {
                _stepStarted = true;
                MovementAnimation move = (MovementAnimation)gameObject.AddComponent(_animation); 
                move.MovementAnimationEndEvent += onStepAnimationEnd;
                move.Init(_transform, targetPosition, new Parameters(Parameters));
            }
        }
    }

    void Awake()
    {
        _transform = transform;
        _animation = MoveAnimation.GetTypeByEnum();
    }

    void onStepAnimationEnd()
    {
        _stepStarted = false;
        if(StepEndEvent != null) StepEndEvent.Invoke();
    }

}


public enum EAnimationTypes
{
    JumpTowardAnimation
}
