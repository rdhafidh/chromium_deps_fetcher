# ada %@!
	#adas21 #FS;SFD33 
_as= Var('das') # somelongth comment
_as_0= FALSE # somelongth comment
_as_0= 'as!' # somelongth comment
gclient_gn_args = [
  #ad as!~;
  'checkout_libaom',
  'checkout_nacl',
  '"{cros_board}" == "amd64-generic"',
  'checkout_oculus_sdk',
]

vars = { 
  'checkout_libaom':1,
  'checkout_nacl': "SS",
  'checkout_oculus_sdk': FalSe,
  'checkout_oculus_sdk':'',
  "../src": {
    "url": "https://chromium.googlesource.com/chromium/src.git@df35166fd2ae545e9d31701a2d9b9cb286dc5ad6",
    "condition": "checkout_chromium",
  },
}

s=[
]