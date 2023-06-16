using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public float speed = 5f; // Normal movement speed
    public float slowSpeed = 2f; // Slow moving speed

    private Vector2 direction; // Direction of movement

    public float barValue = 100f; // Indicative bar value
    public float timerBarValue = 1f; // Timer to affect the bar value

    public float timerDrunkMove = 3f; // Timer for the Drunk Move
    public float timeDrunkLapse = 3.5f; // Lapse time in the drunk move
    public bool goRight = false; // Check for the last diagonal move

    private Rigidbody2D Rb; // Rigidbody2D component reference

    void Start()
    {
        Rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        float moveX = Input.GetAxis("Horizontal");
        float moveY = Input.GetAxis("Vertical");

        timerBarValue -= Time.deltaTime; // Timer to timeLapse
        timerDrunkMove -= Time.deltaTime; // Timer to timeLapse
        timeDrunkLapse -= Time.deltaTime; // Timer to timeLapse

        if (timerBarValue <= 0) // Check timer and affect barValue
        {
            barValue -= 1f;
            timerBarValue = 1f;
        }

        if (timerDrunkMove <= 0 && barValue >= 50) // Check timer and affect barValue
        {
            if (goRight)
            {   
                moveX = -1f;
                moveY = 1.5f;
            }
            else
            {
                moveX = 1f;
                moveY = -1.5f;
            }

            if (timeDrunkLapse <= 0)
            {
                timerDrunkMove = 3f;
                timeDrunkLapse = 3.5f;

                goRight = !goRight;
            }
        }

        direction = new Vector2(moveX, moveY).normalized; // Normalized Move

        if (Input.GetKey(KeyCode.P)) // Temporaly reset barValue
        {
            barValue = 100;
        }

        if (Input.GetKey(KeyCode.L)) // Temporaly set barValue
        {
            barValue = 0;
        }
    }

    void FixedUpdate()
    {
        // Adjust the speed of the character according to the bar value
        if (barValue < 50)
        {
            Rb.velocity = direction * slowSpeed;
        }
        else
        {
            Rb.velocity = direction * speed;
        }
    }
}