#ifndef _RESTAPI_H_
#define _RESTAPI_H_

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

#include <memory>
#include <thread>

class RestApi {

 public:

  RestApi(const std::string address = "127.0.0.1", int port = 12345);
  ~RestApi() = default;

  //initialize endpoint
  void init();

  // start server
  void start();
 private:
  // pistache 回调函数
  void processHandler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response_writer);
 private:
  Pistache::Address m_address;
  Pistache::Rest::Router m_router;
  std::shared_ptr<Pistache::Http::Endpoint> pm_endpoint;
};

#endif  // _restapi_h_
