//PPP3/ch03_console_multiple_asteroids_phase_3/ch03_console_multiple_asteroids_phase_3.cpp

// - Ship and asteroid wraps around canvas borders radius <= x < canvas_width - radius
//                                                 radius <= y < canvas_height - radius
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
	int                  id{ 0 };
	Vector2        position{ 0 };
	Vector2        velocity{ 0 };
	double           radius{ 0.5 };

};

struct GameState
{
	double  canvas_width{ 80 };
	double canvas_height{ 20 };
	double       delta_v{ 1 };
	int   asteroid_count{ 0 };
	bool         is_quit{ false };
};

int main()
{
	GameState gs;
	ShipState ship;

	std::vector<AsteroidState> asteroids;
	asteroids.push_back({ .id = 1, .position{5, 18}, .velocity{0.2, -0.4} });
	asteroids.push_back({ .id = 2, .position{8, 14}, .velocity{0.12, 0.4} });
	asteroids.push_back({ .id = 3, .position{14, 10}, .velocity{0.3, -0.25} });
	asteroids.push_back({ .id = 4, .position{46, 16}, .velocity{-0.2, -0.4} });
	asteroids.push_back({ .id = 5, .position{73, 8}, .velocity{-0.5, 0.8} });

	ship.position = { .x = gs.canvas_width * 0.5, .y = ship.radius * 2 };

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
			ship.position.x += gs.canvas_width - 2 * ship.radius;

		while (ship.position.x >= gs.canvas_width - ship.radius)
			ship.position.x -= gs.canvas_width - 2 * ship.radius;

		while (ship.position.y < ship.radius)
			ship.position.y += gs.canvas_height - 2 * ship.radius;

		while (ship.position.y >= gs.canvas_height - ship.radius)
			ship.position.y -= gs.canvas_height - 2 * ship.radius;

		for(AsteroidState& asteroid : asteroids)
		{
			asteroid.position.x += asteroid.velocity.x;
			asteroid.position.y += asteroid.velocity.y;

			// wrap the asteroid when crossing the canvas border
			while (asteroid.position.x < asteroid.radius)
				asteroid.position.x += gs.canvas_width - 2 * asteroid.radius;

			while (asteroid.position.x >= gs.canvas_width - asteroid.radius)
				asteroid.position.x -= gs.canvas_width - 2 * asteroid.radius;

			while (asteroid.position.y < asteroid.radius)
				asteroid.position.y += gs.canvas_height - 2 * asteroid.radius;

			while (asteroid.position.y >= gs.canvas_height - asteroid.radius)
				asteroid.position.y -= gs.canvas_height - 2 * asteroid.radius;

			double difference_x = ship.position.x - asteroid.position.x;
			double difference_y = ship.position.y - asteroid.position.y;
			double radius_sum = ship.radius + asteroid.radius;
			//check distance between ship and asteroid
			if ((difference_x * difference_x) + (difference_y * difference_y) <= (radius_sum * radius_sum))
			{
				std::cout << "HIT!";
				return 1;
			}
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(16));
		ticks++;

		// Only display output
		if (ticks % 15 == 0)
		{
			double deg = ship.angle * 180 / std::numbers::pi;
			if (SYSTEM_CLS) system("cls");
			std::cout << "sx: " << ship.position.x << ", sy: " << ship.position.y << ", svx: "
				<< ship.velocity.x << ", svy: " << ship.velocity.y << ", angle: " << deg << "\n\n";
			for (AsteroidState asteroid : asteroids)
			{
				std::cout << "asteroid " << asteroid.id << " x: " 
					<< asteroid.position.x << ", y: " << asteroid.position.y << "\n\n";
			}
		}
	}

	return 0;
}