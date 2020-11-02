using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class MovementAnimation : MonoBehaviour
{
    public abstract void ApplyParameters(Parameters parameters);
    public abstract Vector3 MovementFunction();

    public Vector3 StartPos { get { return _startPos; } }
    public Vector3 TargetPos { get { return _targetPos; } }
    public float AnimationTime { get { return _animation; } }

    public delegate void Action();
    public event Action MovementAnimationEndEvent;

    float _animation = 0;
    Transform _transform;
    Vector3 _startPos;
    Vector3 _targetPos;

    public void Init(Transform transform,Vector3 targetPos, Parameters parameters = null)
    {
        _transform = transform;
        _startPos = _transform.position;
        _targetPos = targetPos;

        if (parameters != null)
        {
            ApplyParameters(parameters);
        }

    }


    void Update()
    {
        _animation += Time.deltaTime;
        _transform.position = MovementFunction();
        if (_animation > 1)
        {
            StopAnimation();
        }
    }

    

    void StopAnimation()
    {
        var currentPos = _transform.position;
        currentPos.y = Mathf.Round(currentPos.y);
        _transform.position = currentPos;
        if (MovementAnimationEndEvent != null) MovementAnimationEndEvent.Invoke();
        Destroy(this);
    }

}
