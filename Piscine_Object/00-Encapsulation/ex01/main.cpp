/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayeku <abougrai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:21:24 by rayeku            #+#    #+#             */
/*   Updated: 2026/02/10 14:15:02 by rayeku           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"

int main() {
    try
    {
        Vector2 size = Vector2(10.f, 5.f);
        Graph graph = Graph(size);

        Vector2 point1 = Vector2(0.f, 0.f);
        Vector2 point2 = Vector2(2.f, 2.f);
        Vector2 point3 = Vector2(5.2f, 2.f);
        Vector2 point4 = Vector2(2.f, 4.f);
        
        graph.addVector(&point1);
        graph.addVector(&point2);
        graph.addVector(&point3);
        graph.addVector(&point4);
        
        cout << graph << endl;
        graph.showGraph();
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() << '\n';
    }
    return (0);
}