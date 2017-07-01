///  Handles library account authentication. Protocol should be implemented
///  by any view controller responsible for handling signing in and out.

import Foundation


@objc protocol NYPLAccountAuthProtocol {
  func didBeginLoggingIn()
  func didFinishLoggingIn(_ data: Data?, _ response: URLResponse?, _ error: Error?)
  func errorLoggingIn()
}

final class NYPLAccountAuthManager : NSObject, URLSessionDelegate {
  
  let userBarcode: String?
  let userPIN: String?
  let libraryAccount: Account
  let delegate: NYPLAccountAuthProtocol

  init(withAccountUsername user: String?,
       accountPassword pin: String?,
       libraryAccount account: Account,
       authManagerDelegate: NYPLAccountAuthProtocol) {
    
    userBarcode = user
    userPIN = pin
    libraryAccount = account
    delegate = authManagerDelegate
  }
  
  func login() {
    
    delegate.didBeginLoggingIn()
    
    //find test is strings are empty
//    if (userBarcode?.isEmpty ?? false || userPIN?.isEmpty ?? false) {
//      delegate.errorLoggingIn()
//      return
//    }
    
    guard let userBarcode = userBarcode, let userPIN = userPIN else {
      //Log error
      delegate.errorLoggingIn()
      return
    }
    
    validate(userBarcode,userPIN,libraryAccount)
    
  }
  
  fileprivate func validate(_ user:String, _ pin:String, _ account:Account) {
    
    guard let catalogUrlString = account.catalogUrl,
    let catalogUrl = URL.init(string: catalogUrlString) else {
      //No Valid Catalog URL
      return
    }
    
    let session = URLSession.init(configuration: .ephemeral,
                                  delegate: self,
                                  delegateQueue: .main)
    
    let loansUrl = catalogUrl.appendingPathComponent("loans")
    var request = URLRequest(url: loansUrl)
    request.timeoutInterval = 20.0
    request.httpMethod = "HEAD"
    
    let task = session.dataTask(with: request) { (data, response, error) in
      
      self.delegate.didFinishLoggingIn(data, response, error)
      
    }
    
    task.resume()
  }
  
}
