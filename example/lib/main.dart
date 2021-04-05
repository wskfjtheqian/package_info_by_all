import 'package:flutter/material.dart';
import 'dart:async';

import 'package:package_info_by_all/package_info_by_all.dart';

void main() {
  runApp(MyApp());
}

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  String _platformVersion = '';

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Center(
          child: RaisedButton(
            onPressed: () {
              PackageInfo.get().then((value) {
                setState(() {
                  _platformVersion = value.toString();
                });
              });
            },
            child: Text('Running on: $_platformVersion\n'),
          ),
        ),
      ),
    );
  }
}
