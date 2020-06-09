#pragma once

#include <iostream>
#include <string>
#include <map>

class Referee
{
public:
	Referee() = default;
	~Referee() = default;

	void	process_scores_in_file(std::string const& file_name);

	void	print_results(std::ostream& os = std::cout);
private:
	void	_process_one_country_line(std::string const& line);

	std::map<std::string, std::size_t> _m_scores_table;
};