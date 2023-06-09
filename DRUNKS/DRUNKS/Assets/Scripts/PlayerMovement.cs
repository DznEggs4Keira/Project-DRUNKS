using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
    public float speed = 5f; // Normal movement speed
    public float slowSpeed = 2f; // Slow moving speed
    public float irregularityFactor = 0; // Irregularity of movement factor

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
        float moveX = 0f;
        float moveY = 0f;

        // Diagonal at top Right and bottom Left
        if (Input.GetKey(KeyCode.W) && Input.GetKey(KeyCode.D))
        {
            moveY = 0f;
            moveX = 1f;
        }
        else if (Input.GetKey(KeyCode.W) && Input.GetKey(KeyCode.A))
        {
            moveY = 1f;
            moveX = 0f;
        }

        // Diagonal at top Left and bottom Right
        if (Input.GetKey(KeyCode.S) && Input.GetKey(KeyCode.D))
        {
            moveY = -1f;
            moveX = 0f;
        }
        else if (Input.GetKey(KeyCode.S) && Input.GetKey(KeyCode.A))
        {
            moveY = 0f;
            moveX = -1f;
        }

        // Up and Down
        if (Input.GetKey(KeyCode.W))
        {
            moveY = 0.5f;
            moveX = 1f;
        }
        else if (Input.GetKey(KeyCode.S))
        {
            moveY = -0.5f;
            moveX = -1f;
        }

        // Right and Left
        if (Input.GetKey(KeyCode.D))
        {
            moveY = -1f;
            moveX = 1f;
        }
        else if (Input.GetKey(KeyCode.A))
        {
            moveY = 1f;
            moveX = -1f;
        }

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
