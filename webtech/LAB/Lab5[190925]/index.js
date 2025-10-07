

const [userdata,setUserData]=useState(null)

try {
  let result=await axios.post(`${serverUrl}/api/auth/signup`,{
    // get data from form
    name,email,password
  },{withCredentials:true} )
 setUserData(result.data)
  setLoading(false)
  navigate("/customize")
} catch (error) {
  console.log(error)
  setUserData(null)
  setLoading(false)
  setErr(error.response.data.message)
}