<?php


require_once 'Zend/Loader.php';
 Zend_Loader::loadClass('Zend_Gdata');
 Zend_Loader::loadClass('Zend_Gdata_Query');
 Zend_Loader::loadClass('Zend_Gdata_ClientLogin');
class blogger_import
{

 public $blogID;
 
 public $gdClient;
 
/* public function _construct($mail,$pass)
	{
	 $client = Zend_Gdata_ClientLogin::getHttpClient($mail, $pass, 'blogger');
     $this->gdClient = new Zend_Gdata($client);
	
	}
*/
public function auth($mail,$pass){
$client =Zend_Gdata_ClientLogin::getHttpClient($mail,$pass,'blogger');
$this->gdClient = new Zend_Gdata($client);

}
public function setBlogID($val){

$this->blogID=$val;
}


    public function getBlogIDs()
    {
   $query = new Zend_Gdata_Query('http://www.blogger.com/feeds/default/blogs');
        $feed = $this->gdClient->getFeed($query);
        return $feed;
       //print_r($feed);
        //$this->printFeed($feed);
		//$input=0; 
        //id text is of the form: tag:blogger.com,1999:user-blogID.blogs
       /* $idText = explode('-', $feed->entries[$input]->id->text);
        $this->blogID = $idText[2];
       */
	}
	
}
