#include <Referee.hpp>

#include <fstream>

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
	(void)os;
}



/*
**	private methods
*/

void	Referee::_process_one_country_line(std::string const& line)
{
	std::cout << "line: " << line << std::endl;
}