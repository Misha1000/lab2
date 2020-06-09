#include <Referee.hpp>

#include <fstream>
#include <sstream>

/*
**	public methods
*/

void	Referee::process_scores_in_file(std::string const& file_name)
{
	std::ifstream ifs(file_name);

	int count_of_further_lines;
	ifs >> count_of_further_lines;

	std::string line;
	for (int i = 0; i < count_of_further_lines && std::getline(ifs, line); ++i)
	{
		_process_one_country_line(line);
	}
}

void	Referee::print_results(std::ostream& os)
{
	for (auto const& country_score : _m_scores_table)
	{
		std::cout << country_score.first << ": " << country_score.second << std::endl;
	}
}



/*
**	private methods
*/

void	Referee::_process_one_country_line(std::string const& line)
{
	std::stringstream ss(line);

	std::string country_name;
	std::getline(ss, country_name, ',');

	std::size_t total_scores{};

	std::string token;
	while (std::getline(ss, token, ','))
	{
		total_scores += std::stoull(token);
	}

	_m_scores_table[country_name] += total_scores;
}