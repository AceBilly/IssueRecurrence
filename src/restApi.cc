#include "restApi.h"

void RestApi::processHandler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response_writer) {
    response_writer.headers()
        .add<Pistache::Http::Header::Server>("compiler/0.1")
        .add<Pistache::Http::Header::AccessControlAllowOrigin>("*")
        .add<Pistache::Http::Header::AccessControlAllowMethods>("POST")
        .add<Pistache::Http::Header::ContentType>(MIME(Application, Json))
        .add<Pistache::Http::Header::Connection>();

    std::string res = request.body();

    response_writer.send(Pistache::Http::Code::Ok, res);
  }
  
  void RestApi::init() {
    auto opts = Pistache::Http::Endpoint::options().threads(std::thread::hardware_concurrency());
    pm_endpoint->init(opts);
    Pistache::Rest::Routes::Post(m_router,
                                     "/api/issue",
                                     Pistache::Rest::Routes::bind(&RestApi::processHandler, this));
  }
  
   void RestApi::start() {
    pm_endpoint->setHandler(m_router.handler());
    pm_endpoint->serve();
  }
   RestApi::RestApi(const std::string address, int port)
:m_address(address, Pistache::Port(port)), 
pm_endpoint(std::make_shared<Pistache::Http::Endpoint>(m_address)) {}
