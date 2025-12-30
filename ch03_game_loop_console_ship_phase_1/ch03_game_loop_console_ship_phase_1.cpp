//PPP3/ch03_game_loop_console_ship_phase_1/ch03_game_loop_console_ship_phase_1.cpp

#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>
#include <conio.h>
#include <numbers>

const double two_pi = 2.0 * std::numbers::pi;

struct ShipState
{
	double              x{ 0 };
	double              y{ 0 };
	double             vx{ 0 };
	double             vy{ 0 };
	double t_acceleration{ 0.12 };
	double          speed{ 0 };
	double          angle{ std::numbers::pi * 0.5 }; // Up 
	double      turn_rate{ 0.06 }; // ~3.4 degrees
	double      max_speed{ 12 };
	double intertial_drag{ 0.001 };
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
	ShipState ship{ .x = (gs.canvas_width * 0.5) };
	size_t ticks{ 0 };

	while (!gs.is_quit)
	{	
		if(_kbhit())
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
				ship.vx += std::cos(ship.angle) * ship.t_acceleration;
				ship.vy += std::sin(ship.angle) * ship.t_acceleration;
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

		ship.vx *= (1.0 - ship.intertial_drag);
		ship.vy *= (1.0 - ship.intertial_drag);

		while (ship.angle < 0)
			ship.angle += two_pi;

		while (ship.angle >= two_pi)
			ship.angle -= two_pi;

		ship.x += ship.vx;
		ship.y += ship.vy;

		ship.speed = std::sqrt(ship.vx * ship.vx + ship.vy * ship.vy);
		if (ship.speed > ship.max_speed && ship.speed > 0)
		{
			double scale = ship.max_speed / ship.speed;
			ship.vx *= scale;
			ship.vy *= scale;
		}

		if (ship.x < 0 || ship.x > gs.canvas_width)
			ship.x = 0;

		if (ship.y < 0 || ship.y > gs.canvas_height)
			ship.y = 0;

		std::this_thread::sleep_for(std::chrono::milliseconds(16));
		ticks++;

		// Only display output
		if (ticks % 20 == 0)
		{
			system("cls");
			std::cout << "Position: x(" << ship.x << "), y(" << ship.y << ")\n"
				<< "Velocity: vx(" << ship.vx << "), vy("<< ship.vy << ")\n"
				<< "Angle: " << ship.angle << '\n'
				<< "Speed: " << ship.speed << "\n\n";
		}
	}

	return 0;
}