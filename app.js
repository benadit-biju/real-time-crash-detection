/*
 * IoT Accident Detection Dashboard
 *
 * Firebase/cloud integration can be added
 * to receive emergency events and location.
 */


const alertStatus =
    document.getElementById("alertStatus");

const deviceStatus =
    document.getElementById("deviceStatus");

const latitude =
    document.getElementById("latitude");

const longitude =
    document.getElementById("longitude");

const lastEvent =
    document.getElementById("lastEvent");

const alertType =
    document.getElementById("alertType");

const mapButton =
    document.getElementById("mapButton");


let currentLatitude = null;
let currentLongitude = null;


// --------------------------------
// Demo Event Handler
// --------------------------------

function displayEmergencyEvent(event) {

    currentLatitude = event.latitude;
    currentLongitude = event.longitude;

    alertStatus.textContent =
        "EMERGENCY: Possible accident detected";

    deviceStatus.textContent =
        "Online";

    latitude.textContent =
        event.latitude;

    longitude.textContent =
        event.longitude;

    lastEvent.textContent =
        new Date().toLocaleString();

    alertType.textContent =
        event.type || "Automatic accident detection";
}


// --------------------------------
// Open Location
// --------------------------------

mapButton.addEventListener(
    "click",
    () => {

        if (
            currentLatitude === null ||
            currentLongitude === null
        ) {
            alert(
                "Location is not available."
            );

            return;
        }


        const url =
            `https://www.google.com/maps?q=${
                currentLatitude
            },${
                currentLongitude
            }`;

        window.open(
            url,
            "_blank"
        );
    }
);


// --------------------------------
// Cloud Integration
// --------------------------------

/*
 * Recommended cloud structure:
 *
 * /accidentDetection
 *
 *     /device
 *         online: true
 *
 *     /latestAlert
 *         type: "accident"
 *         latitude: 10.000
 *         longitude: 76.000
 *         timestamp: ...
 *
 *     /history
 *         event records...
 *
 *
 * Replace the demo handler with Firebase,
 * MQTT, or a REST API listener.
 */
