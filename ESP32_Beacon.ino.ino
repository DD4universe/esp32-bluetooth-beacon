#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLEBeacon.h>
#include <esp_bt_main.h>
#include <esp_bt_device.h>

// UUID can be anything you like, acts as the unique ID of the beacon
#define BEACON_UUID "12345678-1234-5678-1234-56789abcdef0"

void setBeacon() {
  BLEBeacon oBeacon = BLEBeacon();
  oBeacon.setManufacturerId(0x4C00); // Apple’s manufacturer ID
  oBeacon.setProximityUUID(BLEUUID(BEACON_UUID));
  oBeacon.setMajor(1);   // Major version
  oBeacon.setMinor(1);   // Minor version
  oBeacon.setSignalPower(-59);

  BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();
  BLEAdvertisementData oScanResponseData = BLEAdvertisementData();

  oAdvertisementData.setFlags(0x04); // BR_EDR_NOT_SUPPORTED 0x04

  std::string strServiceData = "";
  strServiceData += (char)26; // Len
  strServiceData += (char)0xFF; // Type
  strServiceData += oBeacon.getData();

  oAdvertisementData.addData(strServiceData);

  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->setAdvertisementData(oAdvertisementData);
  pAdvertising->setScanResponseData(oScanResponseData);
  pAdvertising->setMinPreferred(0x06);
  pAdvertising->setMinPreferred(0x12);
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting ESP32 Beacon...");

  BLEDevice::init("");
  setBeacon();
  BLEDevice::startAdvertising();

  Serial.println("Beacon active!");
}

void loop() {
  // Beacon keeps broadcasting, nothing needed here
}
