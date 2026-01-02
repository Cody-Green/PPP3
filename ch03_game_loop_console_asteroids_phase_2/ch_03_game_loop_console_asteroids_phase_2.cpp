//PPP3/ch03_game_loop_console_asteroids_phase_2/ch03_game_loop_console_asteroids_phase_2.cpp

// - Ship wraps around canvas borders 0 <= x < canvas_width
//                                 0 <= y < canvas_height
// - Ship angle is normalized to 2.0 * pi
// - Ship speed is clamped to max_speed => speed <= max_speed

#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <conio.h>
#include <numbers>

const bool SYSTEM_CLS = false; // for continuous screen clearing
const double TWO_PI = 2.0 * std::numbers::pi;

struct Vector2
{
	double x{ 0 };
	double y{ 0 };
};

struct ShipState
{
	Vector2      position{ 0 };
	Vector2      velocity{ 0 };
	double         radius{ 0.5 };
	double t_acceleration{ 0.12 }; // thrust
	double          speed{ 0 };
	double          angle{ std::numbers::pi * 0.5 }; // Up 
	double      turn_rate{ 0.06 }; // ~3.4 degrees
	double      max_speed{ 12 };
	double intertial_drag{ 0.001 };
};

struct AsteroidState
{
	Vector2        position{ 0 };
	Vector2        velocity{ 0 };
	Vector2 initial_impulse{ 0 };
	double           radius{ 0.5 };

};

struct GameState
{
	double  canvas_width{ 80 };
	double canvas_height{ 20 };
	double       delta_v{ 1 };
	bool         is_quit{ false };
};

int main()
{


	GameState gs;
	ShipState ship;
	AsteroidState asteroid;

	asteroid.position = { gs.canvas_width * 0.5, gs.canvas_height - asteroid.radius * 2};
	asteroid.velocity.y = -0.2;
	ship.position.x = (gs.canvas_width * 0.5);
	
	size_t ticks{ 0 };

	while (!gs.is_quit)
	{
		if (_kbhit())
		{
			char input_key{ 0 };
			input_key = _getch();

			switch (input_key)
			{
			case 'q':
			{
				gs.is_quit = true;
				break;
			}
			case 'w':
			{
				ship.velocity.x += (std::cos(ship.angle) * ship.t_acceleration);
				ship.velocity.y += (std::sin(ship.angle) * ship.t_acceleration);
				break;
			}
			case 'a':
			{
				ship.angle += ship.turn_rate;
				break;
			}
			case 'd':
			{
				ship.angle -= ship.turn_rate;
				break;
			}
			default:
				break;
			}
		}

		double drag = (1.0 - ship.intertial_drag);
		ship.velocity.x *= drag;
		ship.velocity.y *= drag;

		while (ship.angle < 0)
			ship.angle += TWO_PI;

		while (ship.angle >= TWO_PI)
			ship.angle -= TWO_PI;

		ship.speed = std::sqrt(ship.velocity.x * ship.velocity.x + ship.velocity.y * ship.velocity.y);
		if (ship.speed > ship.max_speed && ship.speed > 0)
		{
			double scale = ship.max_speed / ship.speed;
			ship.velocity.x *= scale;
			ship.velocity.y *= scale;
		}

		ship.position.x += ship.velocity.x;
		ship.position.y += ship.velocity.y;

		// wrap the ship when crossing the canvas border
		while (ship.position.x < ship.radius)
			ship.position.x += ship.radius - (ship.radius - gs.canvas_width);

		while (ship.position.x >= gs.canvas_width - ship.radius)
			ship.position.x -= ship.radius - (ship.radius - gs.canvas_width);

		while (ship.position.y < ship.radius)
			ship.position.y += ship.radius - (ship.radius - gs.canvas_width);

		while (ship.position.y >= gs.canvas_height - ship.radius)
			ship.position.y -= ship.radius - (ship.radius - gs.canvas_width);

		asteroid.position.x += asteroid.velocity.x;
		asteroid.position.y += asteroid.velocity.y;

		// wrap the ship when crossing the canvas border
		while (asteroid.position.x < asteroid.radius)
			asteroid.position.x += asteroid.radius - (asteroid.radius - gs.canvas_width);

		while (asteroid.position.x >= gs.canvas_width - asteroid.radius)
			asteroid.position.x -= asteroid.radius - (asteroid.radius - gs.canvas_width);

		while (asteroid.position.y < asteroid.radius)
			asteroid.position.y += asteroid.radius - (asteroid.radius - gs.canvas_width);

		while (asteroid.position.y >= gs.canvas_height - asteroid.radius)
			asteroid.position.y -= asteroid.radius - (asteroid.radius - gs.canvas_width);

		if (((ship.position.x - asteroid.position.x) * (ship.position.x - asteroid.position.x)) + ((ship.position.y - asteroid.position.y) * (ship.position.y - asteroid.position.y)) <= ((ship.radius + asteroid.radius) * (ship.radius + asteroid.radius)))
		{
			std::cout << "HIT!";
			return 1;
		}


		std::this_thread::sleep_for(std::chrono::milliseconds(16));
		ticks++;

		// Only display output
		if (ticks % 20 == 0)
		{
			double deg = ship.angle * 180 / std::numbers::pi;
			if (SYSTEM_CLS) system("cls");
			std::cout << "x: " << ship.position.x << ", y: " << ship.position.y << ", vx: "
				<< ship.velocity.x << ", vy: " << ship.velocity.y << ", angle: " << deg << "\n\n";
		}
	}

	return 0;
}