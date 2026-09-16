#include "../includes/HttpRequest.hpp"
#include "../includes/HttpResponse.hpp"

#include "mocks/MockHttpRequest.hpp"
#include "mocks/MockHttpResponse.hpp"

#include <iostream>

int main (void)
{
    std::cout << "---Testing HttpResponse---" << std::endl;

    HttpRequest getReq = createMockRequest("GET", "/index.html", "");
    HttpResponse res = processRequest(getReq, config);
    
    return 0;
}